	#include <bits/stdc++.h>
	  #define endl "\n"
	  #define ll long long int
	  #define mod 1000000007
	  #define inf 1000000000000000001;
	  using namespace std;
	  int main()
	  {
	    //  #ifndef ONLINE_JUDGE
	    //  // for getting input from input.txt
	    //  freopen("input.txt", "r", stdin);
	    //  // for writing output to output.txt
	    //  freopen("output.txt", "w", stdout);
	    // #endif
	    std::ios::sync_with_stdio(false);
	    cin.tie(NULL);
	    int a;
	    cin>>a;
	   

	   int L=a/100;
		int R=a%100;
		if(1<=L&&L<=12){
		if(1<=R&&R<=12)printf("AMBIGUOUS\n");
		else printf("MMYY\n");
		}else{
		if(1<=R&&R<=12)printf("YYMM\n");
		else printf("NA\n");
		}
		

	  
	
	    
	    return 0;
	  }
