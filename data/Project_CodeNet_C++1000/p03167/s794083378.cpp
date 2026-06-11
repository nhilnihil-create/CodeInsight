#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int rows, columns;
vector<vector<char>> matrix;
vector<vector<int>> dp;
ll int mod = 1000000007;
int x[] = { 1, 0};
int y[] = { 0, 1};
int dfs(int row, int col)
{
    //cout<<row<<" "<<col<<endl;
    if (row >= rows || row < 0 || col >= columns || col < 0)
    {
        return 0;
    }
    if (row == rows - 1 && col == columns - 1)
    {
        return 1;
    }
    if(dp[row][col] != -1) return dp[row][col];
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        int newRow = row + y[i];
        int newCol = col + x[i];
        if (newRow >= rows || newRow < 0 || newCol >= columns || newCol < 0 || matrix[newRow][newCol] == '#')
            continue;

        sum += dfs(newRow, newCol);
    }
    dp[row][col] = sum % mod;
    return dp[row][col];
}

int main()
{
    cin >> rows >> columns;
    matrix = vector<vector<char>>(rows, vector<char>(columns));
    dp = vector<vector<int>>(rows, vector<int>(columns,-1));
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << dfs(0, 0);
}