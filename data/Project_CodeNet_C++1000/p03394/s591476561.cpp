#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N = 0;
    cin >> N;

    vector<int> ans;

    if(N < 4){
        ans.push_back(2);
        ans.push_back(5);
        ans.push_back(63);
        //if(N <= 4) ans.push_back(20);
        //if(N <= 5) ans.push_back(30);
    }
    else{
        ll sum = 0;
        ans.push_back(2); 
        ans.push_back(3); 
        sum += 5;
        int num = 2;
        for(int x = 4; x < 30000; x++){
            if(N - num == 2) break;
            if(x % 2 != 0 && x % 3 != 0) continue;
            ans.push_back(x);
            sum += x;
            num++;
        }

        int rem = sum % 6;
        if(rem == 0){
            ans.push_back(30000);
            ans.push_back(30000-6);
        }
        else if(rem == 1){
            ans.push_back(30000-3);
            ans.push_back(30000-4);
        }
        else if(rem == 2){
            ans.push_back(30000);
            ans.push_back(30000-2);
        }
        else if(rem == 3){
            ans.push_back(30000);
            ans.push_back(30000-3);
        }
        else if(rem == 4){
            ans.push_back(30000);
            ans.push_back(30000-4);
        }
        else if(rem == 5){
            ans.push_back(30000-3);
            ans.push_back(30000-2);
        }
    }

    for(auto&& x : ans){
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}
