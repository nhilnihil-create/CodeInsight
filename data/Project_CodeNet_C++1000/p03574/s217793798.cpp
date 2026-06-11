#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<string> line(H); 
 
  for (int i = 0; i < H; i++) {
    cin >> line.at(i);
  }
  
  for (int i=0; i < H ; i++){
    for (int j =0 ; j < W ; j++){
         if  (line.at(i).at(j) != '#'){  // #じゃないとき
            int bmc = 0;  // count 0
            	if (i != 0){
                    if (j != 0){
	           			if (line.at(i-1).at(j-1) == '#'){
    	               	bmc++;
        	        	}
                    }
            	    if (line.at(i-1).at(j) == '#'){
                	   bmc++;
                	}
                    if (j != W-1){
						if (line.at(i-1).at(j+1) == '#'){
    	               	   bmc++;
        	        	}
                    }
                }
           		if (j != 0){
					if (line.at(i).at(j-1) == '#'){
                   		bmc++;
                	}
                }
           		if (j != W-1){
					if (line.at(i).at(j+1) == '#'){
    	               bmc++;
        	        }
                }
           		if( i !=H-1){
                    if (j != 0){
		           		if (line.at(i+1).at(j-1) == '#'){
    		               bmc++;
        		        }
                    }
					if (line.at(i+1).at(j) == '#'){
                	   bmc++;
                	}
                    if (j != W-1){
						if (line.at(i+1).at(j+1) == '#'){
                   			bmc++;
                		}
                    }
                } //if( i !=H-1){
            	cout << bmc;
         } // end if (line.at(i).at(j) != '#')
      	 else{
           cout << "#" ;
         }
       } // j のループ
       cout << endl;
    } // iのループ
    
//    for(int i= 0 ; i< H ; i++){
//      cout << line.at(i) << endl;
//    }
}
