#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;

int main(){

    int h, w, n; cin >> h >> w >> n;

    int sr, sc; cin >> sr >> sc;

    string s, t; cin >> s >> t;

    int templ = sc, tempu = sr, tempr = sc, tempd = sr;
    bool flag = false;
    for(int i=0; i<n; i++){
        switch(s[i]){
            case 'L': templ--; break;
            case 'U': tempu--; break;
            case 'R': tempr++; break;
            case 'D': tempd++; break;
        }
        // cout << tempr << endl;

        if(templ <= 0 || tempu <= 0 || tempr > w || tempd > h){
            flag = true;
            break;
        }

        switch(t[i]){
            case 'L': if(tempr != 1) tempr--; break;
            case 'U': if(tempd != 1) tempd--; break;
            case 'R': if(templ != w) templ++; break;
            case 'D': if(tempu != h) tempu++; break;
        }
        // cout << tempr << endl;
        // cout << endl;
    }

    cout << (flag ? "NO" : "YES") << endl;

    return 0;
}