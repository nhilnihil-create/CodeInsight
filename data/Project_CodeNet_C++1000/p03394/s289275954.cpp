#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==3){
    	cout << 2<<" "<<5<<" "<<63<<endl;
    	return 0;
    }
    vector<int> v;
    int m=n/8,index=1;
    for(int i=0;i<m;i++)for(int j=1;j<=12;j++)if(j%2==0||j%3==0)v.pb(12*i+j);
    index=12*m;
    n%=8;
    if(n==1)v.pb(index+6);
    else if(n==2){v.pb(index+2);v.pb(index+4);}
    else if(n==3)for(int i=2;i<=6;i+=2)v.pb(index+i);
    else if(n==4){v.pb(index+2);v.pb(index+4);v.pb(index+3);v.pb(index+9);}
    else if(n==5){v.pb(index+2);v.pb(index+4);v.pb(index+3);v.pb(index+9);v.pb(index+6);}
    else if(n==6){v.pb(index+2);v.pb(index+4);v.pb(index+3);v.pb(index+9);v.pb(index+8);v.pb(index+10);}
    else if(n==7){v.pb(index+2);v.pb(index+4);v.pb(index+3);v.pb(index+9);v.pb(index+8);v.pb(index+10);v.pb(index+6);}
    for(auto& i:v)cout << i<<" ";
    cout << endl;
    return 0;
}
