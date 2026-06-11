#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
//#define int long long int

vi len((int)3e5);
int n;
bool check(int x){
 //   debug(x);
    unordered_map<int, int> s;
    int prev = len[0];
    priority_queue<int> q;
    FOR1(i, n-1){
        if(len[i] <= prev){
            if(x == 1)return false;
            s[len[i]] += 1; 
            q.push(len[i]);
            int j = len[i];
            while(j >= 1 && s[j] == x){
                if(j == 1)return false;
                s[j] = 0;
                j--;
                q.push(j);
                s[j]++;
            }
        }else{
            // do nothing here
            // everything after prev should be 0
            while(!q.empty() && q.top() > prev){
                s[q.top()] = 0;
                q.pop();
            }
        }
        //update prev at the end
        prev = len[i];
    }
    return true;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

  //  freopen("in16.txt", "r" , stdin);
    cin >> n;
    FOR(i, n)cin >> len[i];
    int s = 1, e= n;
    int ans =n;
    while(s <= e){
        int mid = (s + e) >> 1;
        if(check(mid)){
            e = mid -1;
            ans = mid;
        }else{
            s = mid + 1;
        }
    }
    cout << ans;
}


