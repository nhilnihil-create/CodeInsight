# include <bits/stdc++.h>

using namespace std;
int main(void){
    int N;
    cin >> N;
    
    std::vector<int> V(N);
    for(int i=0;i<N;i++) cin >> V[i];

    std::vector<int> C(N);
    for(int i=0;i<N;i++) cin >> C[i];
    int sum = 0;
    for(int i=0;i<N;i++){
        if(C[i]<V[i]) sum+=V[i]-C[i];
    }
    
 
    
    
    cout << sum;

    return 0;
    
}
