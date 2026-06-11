#include <bits/stdc++.h>
using namespace std;

int main() {
    int H , W ;
    cin >> H >> W ;
	string S = "";
    char temp;
    for(int i = 0 ; i < H * W ; i++){
    	cin >> temp;
        S += temp;
    }
    for(int i = 0; i < H * W; i++){
    	if(S.at(i) == '#'){
        	cout << "#";
        }
        else{
        	int count = 0;
            int x = i % W;
            int y = i / W;
            if((x > 0 && y > 0) && S.at((x - 1)+ (y - 1) * W) == '#'){
            	count++;
            }
            if((y > 0) && S.at(x + (y - 1) * W) == '#'){
            	count++;
            }
            if((x + 1 < W && y > 0) && S.at((x + 1) + (y - 1) * W) == '#'){
            	count++;
            }
            if(x > 0 && S.at((x - 1)+ y * W) == '#'){
            	count++;
            }
            if(x + 1 < W && S.at((x + 1)+ y * W) == '#'){
            	count++;
            }
            if((x > 0 && y + 1 < H) && S.at(x - 1 + (y + 1) * W) == '#'){
            	count++;
            }
            if((y + 1 < H) && S.at(x + (y + 1) * W) == '#'){
            	count++;
            }
            if((x + 1 < W && y + 1 < H) && S.at(x + 1 + (y + 1) * W) == '#'){
            	count++;
            }
            cout << count;
        }
        if((i + 1) % W == 0){
        	cout << endl;
        }
    }
}
