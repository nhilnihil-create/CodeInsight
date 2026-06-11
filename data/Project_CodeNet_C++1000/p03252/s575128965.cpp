#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    /**/
    vector<int> c1[26],c2[26];
    bool moji[26] = {0};
    for(int i = 0;i < s.size();i++){
        int x = s.at(i) - 'a';
        int y = t.at(i) - 'a';
            c1[x].push_back(i);
            c2[y].push_back(i);
        
        moji[x] = 1;
        moji[y] = 1;
    }
    /**/
    /**/

    int ans[26] = {0};

    for(int i = 0;i < 26;i++){
        if((c1[i].empty())||(ans[i] == -1)) ans[i] = -1;
        else{
            for(int j = 0;j < 26;j++){
                if(c1[i] == c2[j]){
                    ans[i] = -1;
                    ans[j] = -1;
                    break;
                }
            }
        }
    }


    bool a = 1;

    for(int i = 0;i < 26;i++){
       if(ans[i] != -1){
           a = 0;
           break;
       }
    }

    if(a){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }



    return 0;
}