#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	if(N==3){
	    cout << "17 28 125" << endl;
	    return 0;
	}
	vector<int> ans(N);
	int i;
	for(i=0; (i+1)*4<N; ++i){
	    ans[i*4]=i*6+2;
	    ans[i*4+1]=i*6+3;
	    ans[i*4+2]=i*6+4;
	    ans[i*4+3]=i*6+6;
	}
	if(i%2==1){
	    ans[i*4]=i*6+3;
	    if(N%2==0){
	        ans[i*4+1]=i*6+6;
	    }
	    if(N%4==3){
	        ans[i*4+1]=i*6+2;
	        ans[i*4+2]=i*6+4;
	    }
	    if(N%4==0){
	        ans[i*4+2]=i*6+2;
	        ans[i*4+3]=i*6+4;
	    }
	}else{
	    if(N%2==1){
	        ans[i*4]=i*6+6;
	        if(N%4==3){
	            ans[i*4+1]=i*6+2;
	            ans[i*4+2]=i*6+4;
	        }
	    }
	    else{
	        ans[i*4]=i*6+2;
	        ans[i*4+1]=i*6+4;
	        if(N%4==0){
	            ans[i*4+2]=i*6+3;
	            ans[i*4+3]=i*6+9;
	        }
	    }
	}
	cout << ans[0];
	for(int i=1; i<N; ++i) cout << ' ' << ans[i];
	cout << endl;
	return 0;
}
