#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s;
    int i,j;
    for(i=0;i<h;i++){
        string line;
        cin >> line;
        s.push_back(line);
    }

    int dx[8] = {-1,0,1,-1,1,-1,0,1};
    int dy[8] = {-1,-1,-1,0,0,1,1,1};

    int k;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s.at(i).at(j)=='#') continue;
            int counter =0;
            for(k=0;k<8;k++){
                int x = j + dx[k];
                int y = i + dy[k];
                if(x<0 || x>=w) continue;
                if(y<0 || y>=h) continue;
                if(s.at(y).at(x)=='#') counter++;
            }
            s.at(i).at(j) = char(counter + '0');
        }
    }
    for (i=0;i<h;i++)
        cout << s.at(i) << endl;
    
}