#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int right = 0;
    int left = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == 'E') right++;
    }
    ans = left + right;
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == 'W') left++; 
        if(s[i+1] == 'E') right--;
        ans = min(ans,left + right);
    }
    cout << ans << endl;
    return 0;
}
