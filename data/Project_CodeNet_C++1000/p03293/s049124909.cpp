# include <iostream>
using namespace std;

int main(){
    string S,T,identical;
    int i,j;
    cin>>S>>T;
    int length = S.size();
    char rotated_S[S.size()];
    for (i=0;i<length;i++){
        for (j=0;j<length;j++){
            if (i+j<length){
                rotated_S[i+j]=S[j];
            }
            else{
                rotated_S[i+j-length]=S[j];
            }
        }
        rotated_S[length]='\0';
        if(rotated_S==T){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;;
}