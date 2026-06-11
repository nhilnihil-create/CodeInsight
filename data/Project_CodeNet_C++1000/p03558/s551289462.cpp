#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;

const int LG = 18;
const int SZ = (1 << LG);
const double PI = acos(-1);

int bitreverse[SZ];

int Bitreverse(int x)
{
    int y = 0;
    for (int i = 0; i < LG; i++)
    {
        y = y * 2 + (((1 << i) & x) > 0);
    }
    return y;
}

int k;

vector<cd> copier;
cd was[2][LG + 1][SZ + 1];

void precompute(int fl)
{
    for (int len = 1; len <= LG; len++)
    {
        double ang = 2 * PI / (1 << len) * fl;
        cd wlen(cos(ang), sin(ang));
        cd w(1, 0);
        for (int j = 0; j < (1 << (len - 1)); j++)
        {
            was[fl > 0][len][j] = w;
            w = w * wlen;
        }
    }
}

vector<cd> dft(const vector<cd> & a, const int & fl)
{
    vector<cd> b(SZ);
    for (int i = 0; i < SZ; i++)
        b[i] = a[bitreverse[i]];
    for (int len = 1; len <= LG; len++)
    {
        for (int i = 0; i < SZ; i += (1 << len))
        {
            for (int j = 0; j < (1 << (len - 1)); j++)
            {
                cd u = b[i + j], v = b[i + j + (1 << (len - 1))] * was[fl > 0][len][j];
                b[i + j] = u + v;
                b[i + j + (1 << (len - 1))] = u - v;
            }
        }
    }
    return b;
}

vector<int> fft(const vector<int> & b0)
{
    vector<cd> b(SZ), c(SZ);
    vector<int> r(SZ);
    for (int i = 0; i < SZ; i++) b[i].real(b0[i]);
    b = dft(b, 1);
    for (int i = 0; i < SZ; i++) c[i] = copier[i] * b[i];
    c = dft(c, -1);
    for (int i = 0; i < SZ; i++) r[i] = round(c[i].real() / SZ);
    return r;
}

signed main()
{
    precompute(1);
    precompute(-1);
    cin >> k;
    for (int i = 0; i < SZ; i++) bitreverse[i] = Bitreverse(i);
    while (k % 2 == 0) k /= 2;
    while (k % 5 == 0) k /= 5;
    if (k == 1)
    {
        cout << 1;
        return 0;
    }
    vector<int> reach(SZ);
    int klik = 1;
    for (int i = 0; ; i++)
    {
        reach[klik] = 1;
        klik = klik * 10 % k;
        if (klik == 1)
            break;
    }
    vector<int> b = reach;
    reach[0] = 1;
    vector<cd> rr(SZ);
    for (int i = 0; i < SZ; i++) rr[i].real(reach[i]);
    copier = dft(rr, 1);
    for (int i = 1; i <= 45; i++)
    {
        if (b[0] > 0)
        {
            cout << i;
            return 0;
        }
        b = fft(b);
        for (int j = k; j < 2 * k; j++)
        {
            if (b[j] > 0)
            {
                b[j - k] = 1;
                b[j] = 0;
            }
        }
        for (int j = 0; j < k; j++)
            if (b[j]) b[j] = 1;
    }
}
