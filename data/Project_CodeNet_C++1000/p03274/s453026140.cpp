#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    vector<int> x(N);
    vector<int> p(0);
    vector<int> n(0);
    int ans = 1000000000;
    int i,j,dis;

    for(i=0;i<N;i++){
        cin >> x.at(i);
        if(x.at(i) == 0){
            K--;
        }else if(x.at(i) > 0){
            p.push_back(x.at(i));
        }else{
            n.push_back(-x.at(i));
        }
    }
    if(K == 0){
        ans = 0;
    }else{
        reverse(n.begin(),n.end());
        int p_size = p.size();
        int n_size = n.size();
        for(i = min(K,p_size);i >= 0;i--){
            j = K - i;
            if(j > n_size){
                break;
            }

            if(i == 0){
                dis = n.at(j-1);
            }else if(j == 0){
                dis = p.at(i-1);
            }else if(p.at(i-1) > n.at(j-1)){
                dis = p.at(i-1) + 2 * n.at(j-1);
            }else{
                dis = 2 * p.at(i-1) +  n.at(j-1);
            }

            if(dis < ans){
                ans = dis;
            }
        }
    }
    cout << ans << endl;
}