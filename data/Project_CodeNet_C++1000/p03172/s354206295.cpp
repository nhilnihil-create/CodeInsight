#include <iostream>
#include <vector>

using namespace std ;

void print1dvector(vector<int> v){
    for (int i=0 ; i<v.size() ; i++)
        cout << v[i] << " " ;
    cout << "\n" ;
}

void print2dvector(vector<vector<int> > v){
    for (int i=0 ; i<v.size() ; i++){
        for (int j=0 ; j<v[0].size() ; j++)
            cout << v[i][j] << " " ;
        cout << "\n" ;
    }
}

int main(){
    long long int num = 1000000007 ;
    int N, K ;
    cin >> N >> K ;
    
    vector<int> a(N) ;
    
    for (int i=0 ; i<N ; i++)
        cin >> a[i] ;
    
    vector<vector<int> > dp(K+1, vector<int>(N+1, 0)) ;
    
    for (int i=0 ; i<=N ; i++){
        dp[0][i] = 1 ;
    }
    
    for (int j=1 ; j<=N ; j++ ){
        vector<long long int> sum(K+1, 0) ;
        sum[0] = dp[0][j-1] ;
        
        for (int i=1 ; i<=K ; i++){
            sum[i] = sum[i-1] + dp[i][j-1] ;
        }
        
        for (int i=1 ; i<=K ; i++){
            int num_elements = min(i, a[j-1])+1 ;
            if (num_elements == i+1)
                dp[i][j] = sum[i]%num ;
            else
                dp[i][j] = (sum[i]-sum[i-num_elements])%num ;
        }
        
    }
    
    cout << dp[K][N] ;
    
    return 0 ;
}
