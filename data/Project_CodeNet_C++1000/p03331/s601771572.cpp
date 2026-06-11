#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int sum_digit(int a,int b){
    int sum=0;
    while(a>0){
        sum+=a%10;a/=10;
    }
    while(b>0){
        sum+=b%10;b/=10;
    }
    return sum;
}

int main(){
    int n,ans=10000;cin>>n;
    for(int i=1;i<(n/2+1);i++){
        int j=n-i;
        int s=sum_digit(i,j);
        if(s<ans)ans=s;
    }
    cout<<ans<<endl;
}
