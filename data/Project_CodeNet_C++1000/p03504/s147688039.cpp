#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>
 
using namespace std;
typedef long long ll;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")
 
const ll mod = 1e9 + 7;
const ll inf = 1e18;
 
int timeline[200010];
int useline[200010]; // 使っていれば1
int neednum[200010] = {}; // その時間に求められる録画機の数（ラインの数）
 
void resetTimeline(){
    FOR(i, 0, 200010){
        timeline[i] = 0;
        useline[i] = 0;   
    }
}
 
void printArray(int *a, int num){
    FOR(i, 0, num){
        cout << a[i] << " ";
    }
    cout << endl;
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    // input
    int N, channelNum;
    cin >> N >> channelNum;
 
    vector<int> S(N);
    vector<int> T(N);
    vector<int> C(N);
 
    // タイムスケールを2倍にして整数で考える
    FOR(i, 0, N){
        int s, t, c;
        cin >> s >> t >> c;
        s *= 2;
        t *= 2;
        S[i] = s;
        T[i] = t;
        C[i] = c;
    }
 
    // 各チャンネル毎に占有したい時間帯を求める
    FOR(c, 1, channelNum+1){
        resetTimeline();
        FOR(i, 0, N){
            if(C[i]==c){
                timeline[S[i]-1] = 1;
                timeline[T[i]] = -1;
            }
        }
        // いもす
        useline[0] = timeline[0];
        FOR(i, 1, 200010){
            useline[i] = useline[i-1] + timeline[i];
        }
        //
        FOR(i, 0, 200010){
            if(useline[i]>0){
                neednum[i]++;
            }
        }
    }
 
    int answer = neednum[0];
    FOR(i, 0, 200010){
        answer = max(answer, neednum[i]);
    }
 
    p(answer);
    
    return 0;
}