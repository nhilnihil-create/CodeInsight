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
    int A,B,K;
    cin >> A >> B >> K;
    set<int> st;
    for(int i = 1; i <= K; i++){
        int left = A + i - 1; 
        int right = B - (i-1);
        if(left <= B) st.insert(left);
        if(right >= A) st.insert(right);
    }
    auto ite = st.begin();
    for(; ite != st.end(); ite++){
        cout << *ite << endl;
    }
    return 0;
}
