#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string S;
    cin>>S;
    map<char, int> chrmap;
    for(int i=0;i<S.size();++i){
        chrmap[S[i]]++;
    }
    char ans = 'A';
    for(char i='a';i<='z';++i){
        if(chrmap[i]==0){
            ans = i;
            break;
        }
    }
    if(ans=='A'){
        bool can = false;
        int index;
        vector<char> arr;
        char max;
        for(int i=25;i>=1;--i){
            if(S[i-1]<S[i]){
                can = true;
                index = i-1;
                max = S[i-1];
                arr.push_back(S[i]);
                break;
            }
            else {
                arr.push_back(S[i]);
            }
        }
        if(can){
        for(int i=0;i<index;++i){
            cout<<S[i];
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();++i){
            if(S[index]<arr[i]){
                cout<<arr[i]<<endl;
                break;
            }
        }
        }
        else cout<<-1<<endl;
    }
    else cout<<S+ans<<endl;
}
