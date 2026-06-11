#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    vector<int> groups;

    char key = '1';
    int cnt_key = 0;

    for(int i=0;i<N;i++){
        if(S.at(i)==key){
            cnt_key++;
        }
        else{
            groups.push_back(cnt_key);
            key = (key=='0')?'1':'0';
            cnt_key = 1;
        }
    }

    groups.push_back(cnt_key);
    if(groups.size()%2 == 0)groups.push_back(0);

    int max_people = 0;
    if(K >= groups.size()/2){
        max_people = N;
    }
    else{
        for(int i=0;i<groups.size()-2*K;i+=2){
            int sum_groups =  0;
            for(int j=i;j<i+1+2*K;j++){
                sum_groups += groups.at(j);
            }
            if(max_people < sum_groups)max_people = sum_groups;
        }
    }

    cout << max_people << endl;

}