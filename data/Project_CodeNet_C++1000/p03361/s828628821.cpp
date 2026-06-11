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
    int h,w;
    cin >> h >> w;
    //
    vector<string> data(h);
    for(int i=0;i<h;i++){
        cin >> data[i];
    }
    //
    bool all_white = true;
    bool frg = false;
    //
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(data[i][j]!='#'){
                all_white = false;
                frg = true;
                break;
            }
        }
        if(frg){
            break;
        }
    }
    //
    bool can = true;
    bool frag= false;
    if(all_white){
        cout << "Yes" << endl;
    }
    else{
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(data[i][j]=='#'){
                    if(i-1>=0&&i+1<h&&j-1>=0&&j+1<w){
                        if(data[i-1][j]!='#'&&data[i+1][j]!='#'&&data[i][j-1]!='#'&&data[i][j+1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    //
                    else if(i-1>=0&&i+1<h&&j-1>=0){
                        if(data[i-1][j]!='#'&&data[i+1][j]!='#'&&data[i][j-1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    else if(i-1>=0&&i+1<h&&j+1<w){
                        if(data[i-1][j]!='#'&&data[i+1][j]!='#'&&data[i][j+1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    else if(i-1>=0&&j-1>=0&&j+1<w){
                        if(data[i-1][j]!='#'&&data[i][j-1]!='#'&&data[i][j+1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    else if(i+1<h&&j-1>=0&&j+1<w){
                        if(data[i+1][j]!='#'&&data[i][j-1]!='#'&&data[i][j+1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    //
                    else if(i+1<h&&j+1<w){
                        if(data[i+1][j]!='#'&&data[i][j+1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    else if(i+1<h&&j-1>=0){
                        if(data[i+1][j]!='#'&&data[i][j-1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    else if(i-1>=0&&j+1<w){
                        if(data[i-1][j]!='#'&&data[i][j+1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    else if(i-1>=0&&j-1>=0){
                        if(data[i-1][j]!='#'&&data[i][j-1]!='#'){
                            can = false;
                            frag = true;
                            break;
                        }
                    }
                    //
                    else{
                        can = false;
                        frag = true;
                    }
                }
            }
            if(frag){
                break;
            }
        }
        //
        if(can){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}