#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,M,i,j;
    cin >> N >> M;

    vector<int> k(M);
    vector<vector<int>> s(M);
    vector<int> p(M);
    bool flag = true;
    for(i=0;i<M;i++){
        cin >> k.at(i);
        for(j=0;j<k.at(i);j++){
            int a;
            cin >> a;
            s.at(i).push_back(a);
        }
    }
    for(i=0;i<M;i++){
        cin >> p.at(i);
    }
    int bit,count=0,ans=0;
    for(bit=0;bit<(1<<N);bit++){
        flag = true;
        for(j=0;j<M;j++){
            count = 0;
            for(i=0;i<k.at(j);i++){
                if(bit & (1<<s.at(j).at(i)-1)){
                    count++;
                }
            }
            if(count % 2 != p.at(j)){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }

    cout << ans << endl;
}