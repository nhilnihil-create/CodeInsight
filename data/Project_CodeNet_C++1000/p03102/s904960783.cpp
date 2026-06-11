#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,M,C,count=0;
    cin >> N >> M >> C;
    vector<int> B{};
    
    for(int i=0;i<M;i++){
        int b_i;
        cin >> b_i;
        B.push_back(b_i);
    }
    
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<M;j++){
            int a_i;
            cin >> a_i;
            sum += (B.at(j)*a_i);
        }
        if(sum + C > 0) count++;
    }
    
    cout << count << endl;
    
}