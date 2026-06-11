#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, int> odd, even;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(i%2){
            odd[num]++;
        }else{
            even[num]++;
        }
    }

    int o_max = 0, e_max = 0, os = 0, es = 0;
    int ok, ek;
    for(auto& e : odd){
        if(e.second > o_max){
            o_max = e.second;
            ok = e.first;
        }
    }
    for(auto& e : even){
        if(e.second > e_max){
            
            e_max = e.second;
            ek = e.first;
        }
    }

    for(auto& e : odd){
        if(e.first == ok) continue;
        if(e.second > os){
            os = e.second;
        }
    }
    for(auto& e : even){
        if(e.first == ek) continue;
        if(e.second > es){
            es = e.second;
        }
    }

    if(ok != ek){
        cout << n/2-o_max + n/2-e_max << endl;
    }else{
        
        int len1 = n/2-o_max + n/2-es;
        int len2 = n/2-os + n/2-e_max;
        cout << ((len1 < len2)? len1 : len2) << endl;
    }
}