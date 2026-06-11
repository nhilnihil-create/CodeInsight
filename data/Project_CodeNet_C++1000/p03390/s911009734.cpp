#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<double> result;
    double c,d;
    for (int i = 0;i<N;i++){
        cin>>c>>d;
        double a = min(c,d);
        double b = max(c,d);
        double t = a*b;
        if(a==b || a==b-1){
            result.push_back(2*a-2);
        }
        else{
            double c1 = floor(sqrt(t))==sqrt(t)?sqrt(t)-1:floor(sqrt(t));
            if(c1*(c1+1)>=t)
                result.push_back(2*c1-2);
            else
                result.push_back(2*c1-1);
        }

    }
    for(int j = 0;j<result.size();j++)
        cout<<(int)result[j]<<endl;
    return 0;

}