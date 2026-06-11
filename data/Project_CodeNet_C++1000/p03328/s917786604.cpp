/** author: __nishad__ **/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a) for(int i=0; i<a;i++)
#define loop2(i,a,b) for(int i=(a);i<=(b);++i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb push_back
#define pi 3.14159265358979323
#define endl "\n"


int main()
{
    IOS;

    ll i, a, b, num1=1, num2=1, value;
    vector<tuple<int, int, int>> fibo;

    cin>>a>>b;
    ll dif= b-a;

    while(num2 <=999){
        ll sum = 0;

        for(i=1; i<=num2; i++){
            sum = sum + i;
        }

        fibo.pb(make_tuple( num1, sum, num2));
        num2++;
        num1 = sum;
    }

    for(i=0; i<=999; i++){
        if(dif == get<2>(fibo[i])){
            cout<<get<0>(fibo[i]) - a;
            return 0;
        }

    }


}

