#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()
#define allpt_r(v) (v).rbegin(), (v).rend()


const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(vector<T> v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

template <typename T>
void show2dvec(vector<vector<T>> v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

bool in_field(int h, int w, int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    
    double n, m, d, ans;
    cin >> n >> m >> d;

    if (d == 0) ans =  1 / n * (m - 1);
    else
    {
        ans = 2 * (n - d) / (n * n) * (m - 1);
    }
    printf("%.10f\n" , ans);

    return 0;
}
