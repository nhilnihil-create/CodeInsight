#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<cmath>

using namespace std;

typedef long long ll;
#define INF 1000000007

int main(){
    int n;
    string s;
    cin >> n >> s;

    int countR = 0, countB = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'R') countR++;
        else countB++;
    }

    if(countR > countB) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
