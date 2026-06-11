#include <iostream>
#include <vector>

using namespace std ;

int main(){
    int N, K ;
    cin >> N >> K ;
    
    vector<int> a(N) ;
    for (int i=0 ; i<N ; i++)
        cin >> a[i] ;
    
    vector<int> dp (K+1, 0) ;
    
    for (int i=1 ; i<=K ; i++){
        for (int j=0 ; j<N ; j++){
            if (a[j] <= i)
                dp[i] = dp[i] || !dp[i-a[j]] ;
        }
    }
    
    if (dp[K])
        cout << "First\n" ;
    else
        cout << "Second\n" ;
    
    return 0 ;
}
