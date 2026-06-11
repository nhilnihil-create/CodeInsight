#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long


int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            ll q,a,b,c,d;
            cin>>q;
            while(q--){
                cin>>a>>b>>c>>d;
                if( d < b )cout <<"No"<<endl;
              else  if( b-c > 1 ){
                    ll nzd = __gcd( b,d );
                    ll prvi =  ( b-(a%b)-1 )/nzd ;
                    prvi*=nzd;
                    //cout << prvi << " okoo " << nzd <<endl;
                    if( prvi+(a%b) > c ) cout << "No"<<endl;
                    else cout <<"Yes"<<endl;
                }
                else{
                    if( a >= b ) cout<<"Yes"<<endl;
                    else cout <<"No"<<endl;
                }
            }

            return 0;
}





























