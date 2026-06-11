#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iomanip>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  
	int n;
    cin>>n;

    string s;
    int p;
    vector<tuple<string,int,int>> r;
    for(int i=0; i<n; i++){
        cin>>s>>p;
        r.emplace_back(s,100-p,i);
    }

    sort(ALL(r));

    for(int i=0; i<n; i++){
        cout<<get<2>(r[i])+1<<endl;
    }
}