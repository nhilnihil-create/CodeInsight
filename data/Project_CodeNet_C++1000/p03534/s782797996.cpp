#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define era(t) t.erase(unique(be(t)),t.end())
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a')a++;
        else if(s[i]=='b')b++;
        else c++;
    }
    if(abs(a-b)<=1 && abs(b-c)<=1 && abs(c-a)<=1){
        cout << "YES"<<endl;
    }
    else{
        cout << "NO"<<endl;
    }
    return 0;
}
