#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl

const ll mod = 1e9 + 7;
const ll inf = 1e18;

string getLine(char c, int length){
    stringstream ss;
    FOR(i, 0, length){
        ss << c;
    }
    return ss.str();
}

vector<string> grid(100);

// 横に3つとびでドットを塗る
int paintDot(char color, int rowIndex, int maxInkNuM){
    int offset = 0;
    if(rowIndex % 2 == 1){
        offset = 2;
    }

    int i = 0;
    int paintNum = 0;
    while(i < 100 && maxInkNuM - paintNum > 0){
        grid[rowIndex][i+offset] = color;
        i+=4;
        paintNum++;
    }
    return paintNum;
}

void printGrid(){
    FOR(i, 0, 100){
        p(grid[i]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    int A, B;
    cin >> A >> B;
    
    FOR(i, 0, 50){
        grid[i] = getLine('#', 100);
    }
    FOR(i, 50, 100){
        grid[i] = getLine('.', 100);
    }

    // paint by white
    int drawNum = A-1;
    int rowIndex = 0;
    while(drawNum>0){
        int drawnNum = paintDot('.', rowIndex, drawNum);
        drawNum -= drawnNum;
        rowIndex++;
    }

    // black
    drawNum = B-1;
    rowIndex = 51;
    while(drawNum>0){
        int drawnNum = paintDot('#', rowIndex, drawNum);
        drawNum -= drawnNum;
        rowIndex++;
    }

    p("100 100");
    printGrid();
    
    return 0;
}