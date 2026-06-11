#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    map<int, int> e;
    map<int, int> o;
    //配列代入（偶配列と奇配列に分ける）
    for(int i = 0; i < N; i++){
        cin >> v[i];
        if(i % 2 == 0) o[v[i]]++;
        if(i % 2 == 1) e[v[i]]++;
    }
    //すべての値が一致している場合はコーナーケースとして処理
    bool is = true;
    for(int i = 1; i < N; i++){
        if(v[i] != v[i-1]) is = false;
    }
    if(is){
        cout << N/2 << endl;
        return 0;
    }
    //処理部分
    int f_mx_e = 0;
    int f_mx_o = 0;
    int s_mx_e = 0;
    int s_mx_o = 0;
    int e_num;
    int o_num;
    for(auto p : e){
        if(f_mx_e < p.second) s_mx_e = f_mx_e, f_mx_e = p.second, e_num = p.first;
        else if(s_mx_e < p.second) s_mx_e = p.second;
    }
    for(auto p : o){
        if(f_mx_o < p.second) s_mx_o = f_mx_o, f_mx_o = p.second, o_num = p.first;
        else if(s_mx_o < p.second) s_mx_o = p.second;
    }
    int ans = 0;
    if(e_num != o_num){
        ans = N - (f_mx_e + f_mx_o);
    }else{
        int ans1 = N - (f_mx_e + s_mx_o);
        int ans2 = N - (s_mx_e + f_mx_o);
        ans = min(ans1, ans2);
    }
    cout << ans << endl;
    return 0;
}