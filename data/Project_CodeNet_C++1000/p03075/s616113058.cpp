#include <bits/stdc++.h>
using namespace std;

int main(){
vector<int> vec(5);
for(int i=0;i<5;i++){
    cin >> vec.at(i);
}
int k;
cin >> k;
bool b=true;
for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(vec.at(j)-vec.at(i)>k){
            b=false;
        }
    }

}
if(b==true){
    cout << "Yay!" << endl;
}
else{
    cout << ":(" << endl;
}
}

