#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n;i++)
typedef long long ll;
using namespace std;

int main(void){
    // Your code here!
    string S;
    cin >> S;
    int n = S.size();
    int streak = 0;
    int mstreak = 0;
    for(int i = 0;i<n;i++){
        if(S.at(i) == 'A' ||S.at(i) == 'T' ||S.at(i) == 'G' ||S.at(i) == 'C' ){
            streak++;
            mstreak = max(streak,mstreak);
        }
        else{
            streak = 0;
        }
    }
    cout << mstreak << endl;
}