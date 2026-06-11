#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, c;
  cin >> H >> W;
  string s1, s2, s3;
  
  for(int i = 0;i < H;i++){
    if(H != 1){
      if(i==0){
      	cin >> s2 >> s3;
      }else if(i==H-1){
      }else{
      	cin >> s3;
      }
      if(W != 1){  
        for(int j = 0;j < W;j++){
      		c=0;
      		if(s2.at(j) == '.'){
        		if(i==0){
          			if(j==0){
            			if(s2.at(1) == '#')
              				c++;
            			if(s3.at(0) == '#')
              				c++;
            			if(s3.at(1) == '#')
              				c++;
          			}else if(j==W-1){
            			if(s2.at(j-1) == '#')
              				c++;
            			if(s3.at(j-1) == '#')
              				c++;
            			if(s3.at(j) == '#')
              				c++;
          			}else{
            			if(s2.at(j-1) == '#')
              				c++;
            			if(s2.at(j+1) == '#')
              				c++;
            			if(s3.at(j-1) == '#')
              				c++;
            			if(s3.at(j) == '#')
              				c++;
            			if(s3.at(j+1) == '#')
              				c++;
          			}
        		}else if(i==H-1){
          			if(j==0){
            			if(s2.at(1) == '#')
              				c++;
            			if(s1.at(0) == '#')
              				c++;
            			if(s1.at(1) == '#')
              				c++;
          			}else if(j==W-1){
            			if(s2.at(j-1) == '#')
              				c++;
            			if(s1.at(j-1) == '#')
              				c++;
            			if(s1.at(j) == '#')
              				c++;
          			}else{
            			if(s2.at(j-1) == '#')
              				c++;
            			if(s2.at(j+1) == '#')
              				c++;
            			if(s1.at(j-1) == '#')
              				c++;
            			if(s1.at(j) == '#')
              				c++;
            			if(s1.at(j+1) == '#')
              				c++;
          			}
        		}else{
          			if(j==0){
            			if(s1.at(0) == '#')
              				c++;
            			if(s1.at(1) == '#')
              				c++;
            			if(s2.at(1) == '#')
              				c++;
            			if(s3.at(0) == '#')
              				c++;
            			if(s3.at(1) == '#')
              				c++;
          			}else if(j==W-1){
            			if(s1.at(j-1) == '#')
              				c++;
            			if(s1.at(j) == '#')
              				c++;
            			if(s2.at(j-1) == '#')
              				c++;
            			if(s3.at(j-1) == '#')
              				c++;
            			if(s3.at(j) == '#')
              				c++;
          			}else{
            			if(s1.at(j-1) == '#')
              				c++;
            			if(s1.at(j) == '#')
              				c++;
            			if(s1.at(j+1) == '#')
              				c++;
            			if(s2.at(j-1) == '#')
              				c++;
            			if(s2.at(j+1) == '#')
              				c++;
            			if(s3.at(j-1) == '#')
              				c++;
            			if(s3.at(j) == '#')
              				c++;
            			if(s3.at(j+1) == '#')
              				c++;
          			}
        		}
        		cout << c;
      		}else{
      			cout << '#';
      		}
    	}
      }else{
      	c=0;
      	if(s2.at(0) == '.'){
        	if(i==0){
          		if(s3.at(0) == '#')
            		c++;
        	}else if(i==H-1){
          		if(s1.at(0) == '#')
            		c++;
        	}else{
          		if(s1.at(0) == '#')
            		c++;
          		if(s3.at(0) == '#')
            		c++;
        	}
        	cout << c;
      	}else{
        	cout << '#';
      	}
      }      
      cout << endl;
      s1=s2;
      s2=s3;
    }else{
      cin >> s1;
      if(W != 1){
      	for(int j = 0;j < W; j++){
        	c=0;
        	if(s1.at(j) == '.'){
        		if(j==0){
          			if(s1.at(1) == '#')
            			c++;
        		}else if(j==W-1){
          			if(s1.at(j-1) == '#')
            			c++;
        		}else{
          			if(s1.at(j-1) == '#')
            			c++;
          			if(s1.at(j+1) == '#')
            			c++;
        		}
        		cout << c;
        	}else{
              cout << '#';
            }
        }
      }else{
        if(s1.at(0) == '.')
          cout << 0;
        else
          cout << '#';
      }
      cout << endl;
    }
  }
}
