#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;


int n;
vector<int> v;

vector<int> del(vector<int> a, int p){
    vector<int> ans;
    for(int i = 0;i < a.size();i++){
        if(p != i){
            ans.push_back(a[i]);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        int val;
        cin >> val;
        v.push_back(val);
    }
    vector<int> op;
    for(int i = 1;i <= n;i++){
        int pos = -1;
        for(int j = v.size();j >= 1;j--){
            if(v[j - 1] == j){
                pos = j - 1;
                break;
            }
        }
        if(pos == -1){
            cout << -1 << endl;
            return 0;
        }else{
            v = del(v, pos);
            op.push_back(pos + 1);
        }
    }
    reverse(op.begin(), op.end());
    for(auto val : op){
        cout << val << endl;
    }
    return 0;
}
