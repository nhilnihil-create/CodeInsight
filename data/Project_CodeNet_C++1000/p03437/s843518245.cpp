#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional> // std::function<void(int)>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int Dy[8] = {-1,-1,0,1,1,1,0,-1};
int Dx[8] = {0,1,1,1,0,-1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 111111;
signed main(){
    int a,b;
    cin>>a>>b;
    if(a%b==0)cout<<-1<<endl;
    else{
        for(int i=1;i<d5;i++){
            if(a*i%b!=0){
                cout<<a*i<<endl;
                return 0;
            }
        }
    }
}