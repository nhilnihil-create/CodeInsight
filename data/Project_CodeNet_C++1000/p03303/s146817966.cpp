#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    string s;
    int w;
    cin>>s>>w;

    for(int i=0;i<s.size();i+=w){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}