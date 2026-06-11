#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    vector<int> initial;
    vector<int> initial_list;
    vector<string> word_list;
    int tmp_initial;
    for(int i=0; i<s.size(); i++){
        tmp_initial = s[i]-'a';
        initial.push_back(tmp_initial);
    }

    sort(initial.begin(),initial.end());
    initial_list.push_back(initial[0]);

    for(int i=1; i<initial.size(); i++){
        if(initial[i-1]!=initial[i]){
            initial_list.push_back(initial[i]);
        }
    }

    for(int i=0; i<5; i++){
        char c=initial_list[i]+'a';
        for(int j=0; j<s.size(); j++){
            if(s[j]==c){
                string w;
                w+=s[j];
                word_list.push_back(w);
                for(int k=1; k<5; k++){
                    if(j+k<s.size()){
                        w+=s[j+k];
                        word_list.push_back(w);
                    }
                }
            }
        }
    }

    sort(word_list.begin(), word_list.end());

    int num_k=1;
    if(num_k==k){
        cout << word_list[0] << endl;
    }else{
        for(int i=1; i<word_list.size(); i++){
            if(word_list[i-1]!=word_list[i]){
                num_k++;
                if(num_k==k){
                    cout << word_list[i] << endl;
                    break;
                }
            }
        }
    }

    return 0;
}