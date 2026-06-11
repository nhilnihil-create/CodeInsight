#include <iostream>
#include <vector>
using namespace std;
typedef std::vector<double> vd;
int main(){
	int n;
  	cin>>n;
  	vector<int> arr(n);
  	int c1 = 0, c2 = 0, c3 = 0;
  	for(int i = 0;i<n;i++){
    	cin>>arr[i];
      	if(arr[i]==1) c1++;
      	else if(arr[i]==2) c2++;
      	else c3++;
    }
    vector<vector<vd>> probs(n+1, vector<vd>(n+1, vd(n+1)));
   	vector<vector<vd>> exp(n+1, vector<vd>(n+1, vd(n+1)));
  	probs[c1][c2][c3] = 1.0;
  	exp[c1][c2][c3] = 0.0;
  	int m = c1 + 2*c2 + 3*c3;
	for(int k = c3 ;k>=0;k--){
  		for(int j = n-k;j>=0;j--){
      		for(int i=n-j-k;i>=0;i--){
			  if(i+2*j+3*k>m || i+j+k >n ) continue;

              if(i==0 && j==0 && k==0) continue;
              	double p = double(n-i-j-k)/n;
              	double psofar = probs[i][j][k];
              	double expsofar = exp[i][j][k];
              	double exphere = p/(1-p);
				if(i>0){
                  	double ps =  i/(n*(1-p));
                	probs[i-1][j][k] +=  psofar * ps;
                  	exp[i-1][j][k] += ps * (expsofar+psofar*exphere);
                }

              	if(j>0){
                  	double ps = double(j)/(n*(1-p));
                	probs[i+1][j-1][k] += psofar *  ps;
                  	exp[i+1][j-1][k] += ps * (expsofar+ psofar*exphere);
                }

            	if(k>0){
                  	double ps = double(k)/(n*(1-p));
                	probs[i][j+1][k-1] +=  psofar * ps;
                  	exp[i][j+1][k-1] +=  ps * (expsofar+psofar*exphere);
                }
            
            }
        }
	}
  printf("%.13f", m + exp[0][0][0]);
}