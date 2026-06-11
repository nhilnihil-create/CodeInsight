#include"bits/stdc++.h"
using namespace std;

int main(){
    int l;
    cin >> l;
    //rは頂点数
    //2^(頂点数-1)だけパスが作れるので、2^rがlを超えるような最小のrが頂点数となる
    int r = 1;
    for (int i = 1; i<=20; i++){
        if (pow(2,i)>l) {
            r = i;
            break;
        }
    }
    queue<vector<int>> x;
    int rm = l-1;
    //もし辺iから辺rに長さxの辺を貼ったとすると、2^(i-1)個の新しいパスができる
    //このとき、そのパスの長さをrm,rm-1,...,rm-2^(i-1)+1とすると、rm-2^(i-1)+1が2^r以上であれば良い
    //そしてx=rm-2^(i-1)+1となる
    for (int i = r; i>0; i--){
        if (rm - pow(2,i-1) + 1 >= pow(2,r-1)){
            x.push({i,r,rm-(int)pow(2,i-1)+1});
            rm -= pow(2,i-1);
        }
    }
    cout << r << " " << (r-1)*2 + x.size() << endl;
    for (int i = 1; i<r; i++){
        cout << i << " " << i+1 << " " << 0 << endl;
        cout << i << " " << i+1 << " " << (int)pow(2,i-1) << endl;
    }
    vector<int> ans(3);
    int k = (int)x.size();
    for (int i = 0; i<k; i++){
        ans = x.front(); x.pop();
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
}
