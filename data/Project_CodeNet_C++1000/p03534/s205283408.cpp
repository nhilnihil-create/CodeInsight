#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    vector<LL> count(3,0);

    for(int i = 0; i < str.size(); i++){
        count[str[i]-'a']++;
    }

    LL tmp1 = count[1] - count[0];
    LL tmp2 = count[2] - count[0];

    if(abs(tmp1) <= 1 && abs(tmp2) <= 1 && abs(tmp1-tmp2) <= 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}