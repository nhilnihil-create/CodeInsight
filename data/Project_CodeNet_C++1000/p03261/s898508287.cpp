#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>

#define N_size 100000000000

using namespace std;

int main(){
    int N,wordsuu,copysuu;
    cin  >> N;
    vector<string> W(N),copyW(N);
    bool shiritori = true;
    
    for(int i = 0;i < N;i++){
        cin >> W.at(i);
        copyW.at(i) = W.at(i);
    }

    sort(copyW.begin(),copyW.end());
    copyW.erase(unique(copyW.begin(),copyW.end()),copyW.end());

    copysuu = copyW.size();


    if(copysuu != N)
        shiritori = false;
    
    char kashiramoji;

    for(int i = 0;i < N;i++){
        wordsuu = W.at(i).size();
        if(i >= 1 && kashiramoji == W.at(i).at(0)){
            kashiramoji = W.at(i).at(wordsuu -1);
        }else if(i == 0){
            kashiramoji = W.at(i).at(wordsuu -1);
        }else{
            shiritori = false;
            break;
        }
    }

    if(shiritori)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    


}