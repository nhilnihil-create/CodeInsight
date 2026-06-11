// C++ program to demonstrate insertion 
// into a vector of vectors 



#include <iostream> 
#include <vector> 
using namespace std; 


main() 
{ 
    
	int n;
	cin >> n;
	vector<vector<int> > vec; 
    vector<vector<int> > dp(n, vector<int>(3,0)); 

	for (int i = 0; i < n; i++) { 
		vector<int> v1; 
		for (int j = 0; j < 3; j++) { 
		    int val ;
		    cin >> val;
		    v1.push_back(val);
		} 
		vec.push_back(v1); 
	} 

	int maximum = -99999999;
	if(n==1){
	    for(int i=0;i<3;i++){
	        maximum = std::max(vec[0][i], maximum);
	    }
	}
	else{
	    dp[0][0] = vec[0][0],dp[0][1] = vec[0][1],dp[0][2] = vec[0][2];
	    for(int i = 1; i < n; i++ ){
	        for(int j =0; j< 3; j++){
	            int larger = -100000;
	            for(int k=0;k<3;k++){
	              if(k!=j)
	               larger = std::max(dp[i-1][k], larger);
	            }
	            dp[i][j] = vec[i][j] + larger;
	        }
	    }
        for(int i=0;i<3;i++){
            maximum =  std::max(dp[n-1][i], maximum);
        }
	}
	cout << maximum;
} 
