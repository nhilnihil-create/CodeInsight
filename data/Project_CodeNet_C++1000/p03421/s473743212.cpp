#include <iostream>
#include <vector>

using namespace std;

int main(){
    long N, A, B;
    cin >> N >> A >> B;
    if(A+B > N+1 || A*B < N){
        cout << -1 << endl;
    }else{
        vector<int> v;
        v.push_back(A);
        for(int i = 1; i < B; i++){
            if(i <= (N-A)%(B-1)) v.push_back((N-A)/(B-1)+1);
            else v.push_back((N-A)/(B-1));
        }
        int tmp = N;
        vector<int> ans;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i]; j++){
                ans.push_back(tmp-v[i]+j+1);
            }
            tmp -= v[i];
            //cout << v[i] << ' ';
        }
        //cout << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i == ans.size()-1) cout << endl;
            else cout << ' ';
        }
    }
}