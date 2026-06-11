
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
    	int N;
    	cin>>N;
    	
    	vector<int> vec(N+1);
    	for (int i = 0 ;i<N;i++){
    		cin >> vec.at(i); 
    	}
    	sort(vec.begin(), vec.end()); 
    	
    	int A=0;
    	int B=0;
    	
    	for (int i = N; i>0 ; i--){
    	  if (i%2 == N%2){
    	  	A += vec.at(i);
    	  }else{
    	  	B += vec.at(i);
    	  }
    	}
    	cout << A-B;
    }