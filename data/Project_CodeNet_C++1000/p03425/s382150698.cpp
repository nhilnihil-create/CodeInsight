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
    int N;
    cin >> N;
    int name[5];
    for(int i = 0; i < 5; i++) name[i] = 0;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(s[0] == 'M') name[0]++;
        if(s[0] == 'A') name[1]++;
        if(s[0] == 'R') name[2]++;
        if(s[0] == 'C') name[3]++;
        if(s[0] == 'H') name[4]++;
    }
    ll allcount = 0;
    for(int bit = 0; bit < 1<<5; bit++){
        int temp = bit;
        int count = 0;
        int idx = 0;
        vector<int> num;
        while(temp > 0){
            if(temp & 1){
                count++;
                num.emplace_back(idx);
            }
            idx++;
            temp >>= 1;
        }
        if(count != 3) continue;
        ll smallcount = 1;
        for(int a : num){
            smallcount *= name[a];
        }
        allcount += smallcount;
    }
    cout << allcount << endl;
    return 0;
}
