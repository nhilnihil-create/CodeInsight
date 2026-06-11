#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> one,two,three;
    rep(i,0,n){
        int p;
        cin>>p;
        if(p<=a)one.push_back(p);
        else if(a<p&&p<=b)two.push_back(p);
        else three.push_back(p);
    }
    cout<<min({one.size(),two.size(),three.size()})<<endl;
    return 0;
}