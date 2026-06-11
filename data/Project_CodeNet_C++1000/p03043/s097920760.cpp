#include <bits/stdc++.h>
using namespace std;

int need(int current_score, int needed){
    
    int res = 0;
    while(current_score < needed){
        res += 1;
        current_score <<= 1;
    }
    
    return res;
    
}



double solve(int n, int k){
    
    double first_part = (1/(double)n);
    
    double total = 0;
    for(int i = 1; i <= n; i++){
        int heads_needed = need(i, k);
        double second_part = pow(0.5, heads_needed);
        total += second_part;
    }
    
    return first_part*total;
    
}




int main(){
    
    int n, k;
    cin >> n >> k;
    
    cout << setprecision(9) ;
    
    cout << solve(n, k) << endl;
    
    
}
