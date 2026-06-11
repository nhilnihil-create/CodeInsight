#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e7;

int main(){
    int D;
    ll G;
    cin >> D >> G;
    vector<ll> p(D + 1, 0), c(D + 1, 0);

    for (int i = 1; i <= D; i++)
    {
        cin >> p[i] >> c[i];
    }
    
    int ans = INF;
    for (int bit = 1; bit < (1<<(D+1)); bit++)
    {
        int temp = 0;
        ll sum = 0;
        //cerr << bitset<10>(bit) << endl;
        for (int i = 1; i <= D; i++)
        {
            if (bit & (1<<i))
            {
                //cerr<<"i="<< i <<"marked" << endl;
                sum += 100 * i * p[i] + c[i];
                
                temp += p[i];
            }   
        }
        // cerr << "sum="<<sum << "temp=" << temp<< endl;

        if (sum >= G)
        {
            ans = min(ans, temp);
        } else
        {
            for (int i = D; i > 0; i--)
            {
                if (sum >= G)
                {
                    break;
                }
                
                if (bit & (1<<i))
                {
                    continue;
                }                
                for (int j = 1; j < p[i]; j++)
                {
                   
                    
                    sum += 100 * i;
                    temp++;

                      if (sum >= G)
                    {
                        // cerr <<"temp=" << temp <<endl;
                         ans = min(ans, temp);
                        break;
                    }
                   
                    
               }
                   
            }           
        }
        
        // ans = min(ans,temp);
    }
    
    cout << ans << endl;
    return 0;
}