#include <bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// header area
void dfs(int keta, string tmp, vector<string> &dfs_753, int N){
    if(keta>=10) return;

    if(keta>0){
        bool flag3 = tmp.find('3')!=string::npos;
        bool flag5 = tmp.find('5')!=string::npos;
        bool flag7 = tmp.find('7')!=string::npos;
        if(N>=stoi(tmp) && flag3 && flag5 && flag7){
            // cout << "tmp: "<< tmp <<  endl;
            dfs_753.push_back(tmp);
        }
    }
    for(char i:{'3', '5', '7'}){
        dfs(keta+1, tmp+i, dfs_753, N);
    }
}

int main(){
    int N; cin >> N;
    vector<string> dfs_753;

    dfs(0, "", dfs_753, N);    // N以下、10桁までの値の列挙

    cout << dfs_753.size() << endl;

    return 0;
}