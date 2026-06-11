#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> v(h);

    for(size_t i=0; i<v.size();i++){
        cin >> v.at(i);
    }

    for(size_t i=0;i<v.size();i++){
        for(size_t j=0;j<v.at(i).size();j++){

            if(v.at(i).at(j)=='.'){
                int count =0;
                if(i!=0){
                    if(v.at(i-1).at(j)=='#')
                        count++;
                    if(j!=0)
                        if(v.at(i-1).at(j-1)=='#')
                            count++;
                    if(j!=v.at(i).size()-1)
                        if(v.at(i-1).at(j+1)=='#')
                            count++;
                }
                if(i!=v.size()-1){
                    if(v.at(i+1).at(j)=='#')
                        count++;
                    if(j!=0)
                        if(v.at(i+1).at(j-1)=='#')
                            count++;
                    if(j!=v.at(i).size()-1)
                        if(v.at(i+1).at(j+1)=='#')
                            count++;
                }
                if(j!=0)
                    if(v.at(i).at(j-1)=='#')
                        count++;
                if(j!=v.at(i).size()-1)
                    if(v.at(i).at(j+1)=='#')
                        count++;
                if(j==v.at(i).size()-1)
                    cout << count <<endl;
                else
                    cout << count;
            }else{
                if(j==v.at(i).size()-1)
                    cout << '#' <<endl;
                else
                    cout << '#';
            }
        }
    }
}