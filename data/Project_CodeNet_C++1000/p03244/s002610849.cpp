#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

void read();
template<typename First, typename... Rest> void read(First& first, Rest&... rest);
void write();
template<typename First, typename... Rest> void write(First first, Rest... rest);
template<typename T> void write_vec(vector<T>& v, char divider);

int main(){
    int n;
    read(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        read(v[i]);
    }
    map<int, int> mp1;
    map<int, int> mp2;
    for(int i = 0; i < n; i++){
        if(i & 1){
            mp1[v[i]]++;
        }
        else{
            mp2[v[i]]++;
        }
    }
    priority_queue<pair<int, int>> q1;
    for(auto i = mp1.begin(); i != mp1.end(); i++){
        if(i->second) q1.push(make_pair(i->second, i->first));
    }
    priority_queue<pair<int, int>> q2;
    for(auto i = mp2.begin(); i != mp2.end(); i++){
        if(i->second) q2.push(make_pair(i->second, i->first));
    }
    int ans = 0;
    if(q1.top().second != q2.top().second) {
        ans = n - (q1.top().first + q2.top().first);
    }
    else{
        int m1 = q1.top().first;
        int m2 = q2.top().first;
        q1.pop();
        q2.pop();
        int m12 = (q1.empty())? 0 : q1.top().first;
        int m22 = (q2.empty())? 0 : q2.top().first;
        ans = n - max(m12 + m2, m22 + m1);
    }
    write(ans);
    return 0;
}

//配列以外の入力を受け取る
void read(){

}
template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}
//
//配列以外を出力する
void write(){

}
template<typename First, typename... Rest>
void write(First first, Rest... rest){
    cout << first << " ";
    write(rest...);
}
//
//配列を区切って出力する
template<typename T>
void write_vec(vector<T>& v, char divider){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << divider;
    }
}
//