#include<bits/stdc++.h>
#define PII pair<string,string>
#define LL long long int
using namespace std;
int main()
{

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string str, A, B;
    cin >> str;
    for(int i = 0; i < 2 * n; i++)
    {
        if(i < n)
            A+=str[i];
        else
            B+=str[3 * n - i -1];
    }
    map<PII, LL> Maping;
    vector<PII> vv;
    for(int i = 0;  i < (1 << n); i++)
    {
        string gama, sigma, delta, beta;
        for(int j = 0; j < n; j++)
        {
            if((i >> j) & 1)
            {
                gama += A[j];
                sigma += B[j];
            }
            else
            {
                delta += A[j];
                beta += B[j];
            }
        }
        Maping[make_pair(gama, delta)]++;
        vv.push_back(make_pair(sigma,beta));
    }
    LL ans = 0;
    for(auto v : vv)
        ans += Maping[v];
    cout << ans << endl;
    return 0;
}
