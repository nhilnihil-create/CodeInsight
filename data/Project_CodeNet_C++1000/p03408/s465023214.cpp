#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    //blue input
    vector<string> blue(N);
    for(int i = 0; i < N; i++){
        cin >> blue.at(i);
    }
    int M;
    cin >> M;
    //red input
    vector<string> red(M);
    for(int i = 0; i < M; i++){
        cin >> red.at(i);
    }
    //counter
    vector<int> count(N);
    for(int i = 0; i < N ; i++){
        string a;
        a = blue.at(i);
        for(int n = 0; n < N; n++){
            if(a == blue.at(n)){
                count.at(i) += 1;
            }
        }
        for(int n = 0; n < M; n++){
            if(a == red.at(n)){
                count.at(i) -=1;
            }
        }
    }
    //max
    int ans;
    ans = count.at(0);
    for(int i = 0; i < N; i++){
        if(ans < count.at(i)){
            ans = count.at(i);
        }
    }
    if(ans < 0){
        ans = 0;
    }
    cout << ans << endl;
}