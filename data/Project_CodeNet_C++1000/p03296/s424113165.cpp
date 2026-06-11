#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    REP(i,n)cin >> a[i];
    int answer = 0,count = 0;
    REP(i,n-1){
        if(a[i]==a[i+1]){
            count++;
        }else{
            answer += (count+1)/2;
            count = 0;
        }
    }
    answer += (count+1)/2;
    cout << answer << endl;
    return 0;
}