#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i=0;i<H;i++){
        cin >> S[i];
    }
    // 
    vector<vector<string>> data(H, vector<string>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#'){
                data[i][j]='#';
            }
            else{
                if(i==0||i==H-1||j==0||j==W-1){
                    int cnt=0;
                    if(i==0){
                        //
                        if(0<=j-1&&j-1<W){
                            if(S[i][j-1]=='#'){
                                cnt++;
                            }
                        }
                        if(j+1<W){
                            if(S[i][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                        if(i+1<H&&0<=j-1){
                            if(S[i+1][j-1]=='#'){
                                cnt++;
                            }
                        }
                        if(i+1<H){
                            if(S[i+1][j]=='#'){
                                cnt++;
                            }
                        }
                        if(i+1<H&&j+1<W){
                            if(S[i+1][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                    }
                    else if(i==H-1){
                        //
                        if(j-1>=0){
                            if(S[i][j-1]=='#'){
                                cnt++;
                            }
                        }
                        if(j+1<W){
                            if(S[i][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                        if(0<=i-1&&0<=j-1){
                            if(S[i-1][j-1]=='#'){
                                cnt++;
                            }
                        }
                        if(0<=i-1){
                            if(S[i-1][j]=='#'){
                                cnt++;
                            }
                        }
                        if(0<=i-1&&j+1<W){
                            if(S[i-1][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                    }
                    else if(j==0){
                        //
                        if(j+1<W){
                            if(S[i][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                        if(0<=i-1){
                            if(S[i-1][j]=='#'){
                                cnt++;
                            }
                        }
                        if(0<=i-1&&j+1<W){
                            if(S[i-1][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                        if(i+1<H){
                            if(S[i+1][j]=='#'){
                                cnt++;
                            }
                        }
                        if(i+1<H&&j+1<W){
                            if(S[i+1][j+1]=='#'){
                                cnt++;
                            }
                        }
                        //
                    }
                    else if(j==W-1){
                        //
                        if(j-1>=0){
                            if(S[i][j-1]=='#'){
                                cnt++;
                            }
                        }
                        //
                        if(i-1>=0&&j-1>=0){
                            if(S[i-1][j-1]=='#'){
                                cnt++;
                            }
                        }
                        if(i-1>=0){
                            if(S[i-1][j]=='#'){
                                cnt++;
                            }
                        }
                        //
                        if(i+1<H&&j-1>=0){
                            if(S[i+1][j-1]=='#'){
                                cnt++;
                            }
                        }
                        if(i+1<H){
                            if(S[i+1][j]=='#'){
                                cnt++;
                            }
                        }
                        //
                    }
                    data[i][j]=to_string(cnt);
                }
                else{
                int cnt =0;
                //
                if(j-1>=0){
                    if(S[i][j-1]=='#'){
                        cnt++;
                    }
                }
                if(j+1<W){
                    if(S[i][j+1]=='#'){
                        cnt++;
                    }
                }
                //
                if(i-1>=0&&j-1>=0){
                    if(S[i-1][j-1]=='#'){
                        cnt++;
                    }
                }
                if(i-1>=0){
                    if(S[i-1][j]=='#'){
                        cnt++;
                    }
                }
                if(i-1>=0&&j+1<W){
                    if(S[i-1][j+1]=='#'){
                        cnt++;
                    }
                }
                //
                if(i+1<H&&j-1>=0){
                    if(S[i+1][j-1]=='#'){
                        cnt++;
                    }
                }
                if(i+1<H){
                    if(S[i+1][j]=='#'){
                        cnt++;
                    }
                }
                if(i+1<H&&j+1<W){
                    if(S[i+1][j+1]=='#'){
                        cnt++;
                    }
                }
                //
                data[i][j]=to_string(cnt);
                }
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(j==W-1){
                cout << data[i][j] << endl;
            }
            else{
                cout <<  data[i][j] ;
            }
        }
    }
}