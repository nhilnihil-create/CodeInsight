#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
//#include <stack>
#include <climits>
#include <map>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
#define all(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

int n;
int s[400][400];

int jdg(int n){
    int k1 = floor(sqrt(n));
    return k1*(k1+1)==n;
}

int main() {
    cin >> n;
    n*=2;
    if(!jdg(n)){
        put("No");
        return 0;
    }else{
        put("Yes");
        int k = floor(sqrt(n))+1;
        vector<int> b(k);
        b[0] = k-1;
        REP(i,k-1){
            b[i+1] = b[i]+i-2;
        }
        vector<vector<int>> sc(k);
        int cnt = 1;
        REP(i,k-1){
            REP(j,k-1-i){
                sc[i].push_back(cnt);
                sc[i+j+1].push_back(cnt);
                cnt++;
            }
        }
        /*REP(i,n){
            auto itr = lower_bound(all(b),i+1);
            int  d = itr - b.begin();
            s[d][cnt++] =
            
        }*/
        //vector<vector<int>> s(k);
        put(k);
        REP(i,k){
            cout << k-1 << " ";
            REP(j,k-1){
                cout << sc[i][j] << " ";
        }
        put("");
    }
    
        
    }
    return 0;
}

